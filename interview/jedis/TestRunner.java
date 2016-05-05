import org.junit.runner.JUnitCore;
import org.junit.runner.Result;
import org.junit.runner.notification.Failure;

public class TestRunner{

    public static void main(String[] args){
        Result result = JUnitCore.runClasses(SimpleTest.class);
        for(Failure f: result.getFailures()){
            System.out.println(f.toString());
        }
    }
}
