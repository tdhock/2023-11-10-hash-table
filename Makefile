first_letter.out: first_letter
	./first_letter |tee first_letter.out
first_letter: first_letter.c
	gcc first_letter.c -o first_letter
avoid_collisions.out: avoid_collisions
	./avoid_collisions|tee avoid_collisions.out
avoid_collisions: avoid_collisions.c
	gcc avoid_collisions.c -o avoid_collisions
