import random

template = (
"""
$$$ exec p1 : [garbage]
Plateau 15 17:
    01234567890123456
000 .................
001 .................
002 .................
003 .................
004 .................
005 .................
006 .................
007 .................
008 ..O..............
009 .................
010 .................
011 .................
012 ..............X..
013 .................
014 .................
Piece 5 5:
.....
.....
..**.
..*..
.....
"""
)

template = bytearray(template)

i = random.randint(1, len(template)) - 1

char = random.randint(0, 511)
if char >= 256:
	del template[i]
else:
	template[i] = chr(char)

print str(template)