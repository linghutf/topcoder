/*
 * SwtichString.java
 * Copyright (C) 2016 linghutf <linghutf@pc>
 *
 * Distributed under terms of the MIT license.
 */

public class SwtichString
{
    public static void main(String[] args){
        String s = "allow";
        int n=0;
        switch(s){
            case "all":n=1;break;
            case "allo":n=2;break;
            case "allow":n=3;break;
        }
        System.out.println(n);//n=3,说明switch是完全匹配
    }
}

