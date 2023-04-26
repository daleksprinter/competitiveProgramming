TEMPLATE_PATH=template.go
contest=abc215
problem=d

setup:
	mkdir -p $(contest)/code
	echo {a,b,c,d,e,f}\\n | xargs -IXXX cp ${TEMPLATE_PATH} $(contest)/code/XXX.go
	git add .

run:
	go run $(contest)/code/$(problem).go
