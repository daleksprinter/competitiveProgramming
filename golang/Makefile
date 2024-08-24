TEMPLATE_PATH=template.go
contest=
problem=d

setup:
	mkdir -p $(contest)/code
	echo {a,b,c,d,e,f}\\n | xargs -IXXX cp ${TEMPLATE_PATH} $(contest)/code/XXX.go

run:
	go run $(contest)/code/$(problem).go
