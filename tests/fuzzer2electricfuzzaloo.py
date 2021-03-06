#!/usr/bin/env python3

import subprocess
import signal
from random import randrange, choice
from sys import argv
import re

TEMPLATE = (
	"$$$ exec p1 : [garbage]\n"
	"Plateau 15 17:\n"
	"    01234567890123456\n"
	"000 .................\n"
	"001 .................\n"
	"002 .................\n"
	"003 .................\n"
	"004 .................\n"
	"005 .................\n"
	"006 .................\n"
	"007 .................\n"
	"008 ..O..............\n"
	"009 .................\n"
	"010 .................\n"
	"011 .................\n"
	"012 ..............X..\n"
	"013 .................\n"
	"014 .................\n"
	"Piece 5 5:\n"
	".....\n"
	".....\n"
	"..**.\n"
	"..*..\n"
	".....\n"
).encode('ascii')

stdout_re = re.compile(r'-?\d+ -?\d+$')


def do_test(data):
	proc = subprocess.Popen(
		argv[1],
		stdin=subprocess.PIPE,
		stdout=subprocess.PIPE,
		stderr=subprocess.PIPE,
	);
	try:
		stdout, stderr = proc.communicate(input=TEMPLATE, timeout=0.5)
	except subprocess.TimeoutExpired:
		proc.kill()
		return None
	sig = signal.Signals(-proc.returncode).name if proc.returncode < 0 else None
	return stdout, stderr, sig


def fuzz_data_del(data):
	i = randrange(0, len(data))
	return data[:i] + data[i + 1:]


def fuzz_data_change(data):
	i = randrange(0, len(data))
	return data[:i] + bytes([randrange(0, 256)]) + data[i + 1:]


def on_death(ret, stdin):
	print(f"\nProgram killed by {ret[2]}")
	with open('stdin.txt', 'wb') as f:
		f.write(stdin)
	print("You can reproduce this by running:")
	print(f"{argv[1]} < stdin.txt")
	exit()


if len(argv) != 2:
	print(f"Usage: {argv[0]} /path/to/filler")
	exit(1)

stdin = TEMPLATE
i = 0
while 1:
	print(f"\rRan {i + 1} tests", end='')
	i += 1
	stdin = choice((fuzz_data_del, fuzz_data_change))(stdin)
	ret = do_test(stdin)
	if not ret:
		stdin = TEMPLATE
		continue
	if ret[2] or not stdout_re.match(ret[0].decode('ascii')):
		on_death(ret, stdin)
	if not ret[0].strip():
		stdin = TEMPLATE
		continue
print()