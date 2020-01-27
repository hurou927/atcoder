
build:
	go build main.go

run:
	find input -mindepth 1 | xargs -I {} sh -c 'echo "{}"; ./main < {}'
