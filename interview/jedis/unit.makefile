jc=javac

JCFLAGS=~/lib/junit-4.12.jar

LDPATH=.:~/lib/hamcrest-all-1.3.jar:~/lib/junit-4.12.jar

main: SimpleTest TestRunner

SimpleTest: SimpleTest.java
	$(jc) -cp $(JCFLAGS) $<

TestRunner: TestRunner.java
	$(jc) -cp $(JCFLAGS):. $<

test:
	java -cp $(LDPATH) TestRunner
	#org.junit.runner.JUnitCore TestRunner

clean:
	@rm *.class
