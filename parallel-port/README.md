Pin No (DB25)		Signal name			Direction			Register-bit
1					Strobe				In/Out				/Control-0 			
2					Data0				Out					Data-0
3					Data1				Out					Data-1
4					Data2				Out					Data-2
5					Data3				Out					Data-3
6					Data4				Out					Data-4
7					Data5				Out					Data-5
8					Data6				Out					Data-6
9					Data7				Out					Data-7
10					Ack					In					Status-6
11					Busy				In					/Status-7
12					Paper-Out			In					Status-5
13					Select				In					Status-4
14					Linefeed			In/Out				/Control-1
15					Error				In					Status-3
16					Reset				In/Out				Control-2
17					Select-Printer		In/Out				/Control-3
18-25				Ground				-					-

{/control means active low}

control pins from MSB to LSB is 17,16,14,1 - 4 bits [SP,R,L,S]
status pins from MSB to LSB is 11,10,12,13,15 - 5 bits [B,A,P,S,E]
data pins from MSB to LSB is 9,8,7,6..2 - 8 bits.