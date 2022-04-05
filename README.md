# PUSH_SWAP

make
Compile les programmes push_swap & checker

make randomize
Compile le programme randomize

./push_swap $ARG -h -i
Affiche le nombre d'instructions pour ranger la list de $ARG

ARG=$(./randomize 500); time ./push_swap $ARG -h
Affiche le temps que prends l'algo

RANDOMIZE >

make randomize
Compile le programme randomize

ARG=$(./randomize 500)
Met 500 chiffres (de 1 a 500) dans l'ordre aléatoire dans ARG

ARG=$(./randomize 500 0)
Met 500 chiffres (de -2147483648 a 2147483647) dans l'ordre aléatoire dans ARG

TESTER >
ARG=$(./randomize 500); ./push_swap $ARG -h -i

ARG=$(./randomize 100); ./push_swap $ARG | ./checker $ARG

TESTER AVEC BAREME >

./push_swap -r

OU

ARG="2 1 0"; ./push_swap $ARG -v -i
ARG="1 5 2 4 3"; ./push_swap $ARG -v -i
ARG=$(./randomize 5); ./push_swap $ARG -i -h
ARG=$(./randomize 100); ./push_swap $ARG -i -h
ARG=$(./randomize 500); ./push_swap $ARG -i -h

TESTER AVEC UNE TAILLE >
./push_swap -r <nombre d'ints random>


### Score :
![tglory's 42 push_swap Score](https://badge42.vercel.app/api/v2/cl1lnya4f000609mhs5b44u13/project/2170987)

