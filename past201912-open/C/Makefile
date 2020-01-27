
build:
	go build main.go

run:
	find input -mindepth 1 | sort |  xargs -I {} sh -c 'echo "{}"; ./main < {}'
