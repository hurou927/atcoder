
build:
	rustc -o main main.rs

run:
	find input -mindepth 1 | sort |  xargs -I {} sh -c 'echo "{}"; ./main < {}'
