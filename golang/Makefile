TEMPLATE_PATH=template.go
contest=abc220
problem=a

setup:
	mkdir -p $(contest)
	echo {a,b,c,d,e,f}\\n | xargs -IXXX cp ${TEMPLATE_PATH} $(contest)/XXX.go
	git add .

run:
	go run $(contest)/$(problem).go
