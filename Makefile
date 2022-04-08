
EXECS= init-IMT2019012 visitor-IMT2019012 doc-IMT2019012

all: $(EXECS)

init-IMT2019012: init-IMT2019012.c mysemops-IMT2019012.c mysemops-IMT2019012.h
	gcc -o init-IMT2019012 init-IMT2019012.c mysemops-IMT2019012.c

visitor-IMT2019012: visitor-IMT2019012.c mysemops-IMT2019012.c mysemops-IMT2019012.h
	gcc -o visitor-IMT2019012 visitor-IMT2019012.c mysemops-IMT2019012.c

doc-IMT2019012: doc-IMT2019012.c mysemops-IMT2019012.c mysemops-IMT2019012.h
	gcc -o doc-IMT2019012 doc-IMT2019012.c mysemops-IMT2019012.c

clean:
	rm -f $(EXECS)
