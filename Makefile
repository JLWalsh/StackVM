.PHONY: init build clean

SOLUTIONDIR = solution

init:
	git submodule init
	git submodule update

build:
	rm -rf $(SOLUTIONDIR)
	mkdir $(SOLUTIONDIR)
	cd $(SOLUTIONDIR); cmake ../

clean:
	rm -rf $(SOLUTIONDIR)