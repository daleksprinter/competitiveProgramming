TEMPLATE := template.go
contest :=
problem :=
INPUT_DIR := $(contest)/$(problem)/inputs
ANS_DIR := $(contest)/$(problem)/ans
num :=

$(contest):
	mkdir -p $(contest)

$(contest)/$(problem): $(contest)
	mkdir -p $(contest)/$(problem)

$(contest)/$(problem)/main.go: $(contest)/$(problem) $(TEMPLATE)
	cp ${TEMPLATE} $(contest)/$(problem)/main.go

.PHONY: setup
setup: $(contest)/$(problem)/main.go $(INPUT_DIR) $(ANS_DIR)

$(INPUT_DIR):
	mkdir -p $(INPUT_DIR)

$(ANS_DIR):
	mkdir -p $(ANS_DIR)

$(INPUT_DIR)/%: $(INPUT_DIR)
	touch $@

$(ANS_DIR)/%: $(ANS_DIR)
	touch $@

.PHONY: run
run:
	go run $(contest)/$(problem)/main.go

.PHONY: test
test: $(INPUT_DIR)/$(num) $(ANS_DIR)/$(num)
	go run $(contest)/$(problem)/main.go < $(INPUT_DIR)/$(num) | diff - $(ANS_DIR)/$(num)

.PHONY: test-all
test-all:
	for i in $(shell ls $(INPUT_DIR)); do \
		$(MAKE) test num=$$i; \
	done

