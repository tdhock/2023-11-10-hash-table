first_letter.out: first_letter
	./first_letter |tee first_letter.out
first_letter: first_letter.c
	gcc first_letter.c -o first_letter
linear_scan.out: linear_scan
	./linear_scan|tee linear_scan.out
linear_scan: linear_scan.c
	gcc -g linear_scan.c -o linear_scan
avoid_collisions.out: avoid_collisions
	./avoid_collisions|tee avoid_collisions.out
avoid_collisions: avoid_collisions.c
	gcc avoid_collisions.c -o avoid_collisions
