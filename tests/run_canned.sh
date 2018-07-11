#!/bin/bash

if [[ -z "$1" ]]; then
	echo "usage: $0 [program path]"
	exit
fi

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# figure out where to store logs
PROG_NAME="$(basename "$1")"
OUT_PATH="output_$PROG_NAME"
rm -fr "$OUT_PATH"
mkdir "$OUT_PATH"

# run on each test
for file in $SCRIPT_DIR/canned/*; do
	# run in background
	file_name="$(basename "$file")"
	err_log="$OUT_PATH/${file_name}_err"
	out_log="$OUT_PATH/${file_name}_out"
	$1 < "$file" > "$out_log" 2> "$err_log" &

	# Wait for timeout
	pid=$!
	start=$(date +%s)
	while kill -0 $pid &> /dev/null
	do
		elapsed=$(( $(date +%s) - start ))
		if (( elapsed > 1 )); then
			echo -n "Timeout: "
			kill -9 $pid
			break
		fi
		sleep 0.1
	done

	# check return value
	wait $pid &> /dev/null
	signal=$(( $? - 128 ))
	if (( signal > 0 )); then
		echo "$PROG_NAME returned signal $signal on file \"$file\""
	fi

	# delete empty logs
	if [ ! -s "$out_log" ] ; then
		rm "$out_log"
	fi
	if [ ! -s "$err_log" ] ; then
		rm "$err_log"
	fi
done
