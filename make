myls: myls.c myls.h
	gcc -o myls myls.c 

clean:
	rm myls