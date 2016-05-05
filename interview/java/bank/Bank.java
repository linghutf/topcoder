/*class Account{
    private double amount;

    public Account(double amount){
        this.amount = amount;
    }


    public synchronized double getAmount(){
        return this.amount;
    }

    public synchronized void setAmount(double amount){
        this.amount = amount;
    }

}
*/
package bank;

public class Bank{
    private Account[] accounts;

    public Bank(Account[] accounts){
        this.accounts = accounts;
    }

    public synchronized boolean transfer(int fromId,int toId,double money){
        Account from = this.accounts[fromId];
        Account to = this.accounts[toId];
        if(from == null) return false;
        if(from.getAmount()-money<1e-9)
            return false;
        if(to==null) return false;
        from.setAmount(from.getAmount()-money);
        to.setAmount(to.getAmount()+money);
        System.out.printf("账户[%d]向账户[%d]转账:%f,账户[%d]剩余:%f,账户[%d]剩余:%f\n",fromId,toId,money,fromId,from.getAmount(),toId,to.getAmount());
        return true;
    }

    public static void main(String[] args){
        Account[] as={new Account(1000),new Account(1000)};
        Bank bank = new Bank(as);

        Thread t1 = new Thread(new Runnable(){
            public void run(){
                int i=0,n=5;
                while(i++<n){
                    bank.transfer(0,1,100);
                    try{
                        Thread.sleep(1000);
                    }catch(InterruptedException e){
                        e.printStackTrace();
                    }
                }
            }
        });
        Thread t2 = new Thread(new Runnable(){
            public void run(){
                int i=0,n=5;
                while(i++<n){
                    bank.transfer(1,0,150);
                    System.out.println(bank.getTotalAmount());
                    try{
                        Thread.sleep(1000);
                    }catch(InterruptedException e){
                        e.printStackTrace();
                    }
                }
            }
        });

        t1.start();
        t2.start();

        try{
            t1.join();
            t2.join();
        }catch(InterruptedException e){
            e.printStackTrace();
        }
    }

    public synchronized double getTotalAmount(){
        double total = 0;
        for(Account a:this.accounts){
            total+=a.getAmount();
        }
        return total;
    }
}
