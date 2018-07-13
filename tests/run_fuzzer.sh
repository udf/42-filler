#!/bin/bash

if [[ -z "$1" ]]; then
	echo "usage: $0 [program path]"
	exit
fi

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# figure out where to store logs
PROG_NAME="$(basename "$1")"
OUT_PATH="fuzz_$PROG_NAME"
rm -fr "$OUT_PATH"
mkdir "$OUT_PATH"
err_log="$OUT_PATH/stderr"
out_log="$OUT_PATH/stdout"
num_tests=0

while true; do
	# run fuzzer
	fuzz_data=$(python "$SCRIPT_DIR/fuzzer.py")

	# run in background
	$1 > "$out_log" 2> "$err_log" <<< "$fuzz_data" &

	# Wait for timeout
	pid=$!
	start=$SECONDS
	timedout=0
	while kill -0 $pid &> /dev/null
	do
		if (( SECONDS - start > 1 )); then
			kill -9 $pid
			timedout=1
			break
		fi
	done
	if (( timedout )); then
		continue
	fi

	# check return value
	wait $pid &> /dev/null
	signal=$(( $? - 128 ))
	if (( signal > 0 )); then
		echo -e "\n$PROG_NAME returned signal $signal"
		tee "$OUT_PATH/stdin" <<< "$fuzz_data"
		break
	fi
	num_tests=$((num_tests + 1))
	echo -ne "\rRan $num_tests tests"
done
