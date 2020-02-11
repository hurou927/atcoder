
all:
	cargo build && find input -mindepth 1 | sort |  xargs -I {} sh -c 'echo "{}";  ./target/debug/atcoder < {}'
build:
	cargo build

run:
	find input -mindepth 1 | sort |  xargs -I {} sh -c 'echo "{}";  ./target/debug/atcoder < {}'

