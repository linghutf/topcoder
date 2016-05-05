package bank;

class Account{
    private volatile double amount;

    public Account(double amount){
        this.amount = amount;
    }

    public /*synchronized*/ double getAmount(){
        return this.amount;
    }

    public /*synchronized*/ void setAmount(double amount){
        this.amount = amount;
    }
}
