import org.junit.runner.RunWith;
import org.junit.runners.Suite;

@RunWith(Sutie.class)
@Suite.SuiteClasses({
    TestJunit1.class,TestJunit2.class
})

public class JunitTestSuite{
}

import org.junit.Test;
import org.junit.Ignore;
import static org.junit.Assert.assertEquals;

public class TestJunit1{
    String msg = "Robot";
    MessageUtil msgUtil1 = new MessageUtil(msg);

    @Test
    public void testPrintMsg(){
        System.out.println("Inside test");
        assertEquals(msg,msgUtil.printMessage());
    }
}
