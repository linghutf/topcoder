import redis.clients.jedis.Jedis;

public class JedisTest{
    static{
        System.out.println("简单可复制-互联网技术发展的关键!\n因此复杂的技术形式不会发展成社会主流.");
    }
    public static void main(String[] args){
        Jedis jedis = new Jedis("localhost");
        String key = "CN",value = "ZH";
        jedis.set(key,value);
        String value_r = jedis.get(key);
        long ret = jedis.del(key);
        if(ret==0){
            System.out.println("删除失败!");
        }

        System.out.printf("获取值[%s]:[%s]\n",key,value);

        System.out.printf("获取值[%s]:[%s]\n",key,jedis.get(key));

        jedis.append(key,"Wuhan");
        System.out.printf("获取值[%s]:[%s]\n",key,jedis.get(key));

        jedis.append(key," HUST");
        System.out.printf("获取值[%s]:[%s]\n",key,jedis.get(key));

        jedis.shutdown();
    }
}
