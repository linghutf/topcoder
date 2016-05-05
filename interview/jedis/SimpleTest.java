import org.junit.Test;
import org.junit.Assert;

public class SimpleTest{
    @Test
    public void testArrayEquals(){
        byte[] a = "trail".getBytes();
        byte[] b = "CN".getBytes();
        Assert.assertArrayEquals("failed!",a,b);
    }

    @Test
    public void testAssertEquals(){
        Assert.assertEquals("failed!","BK","US");
    }
}
