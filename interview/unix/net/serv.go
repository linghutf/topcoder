package main

import (
	"fmt"
	"net"
	//"os"
	"time"
)

const (
    MAX_CONN_NUMS = 5
)

func EchoFunc(conn net.Conn) {
	defer conn.Close()
	buf := make([]byte, 1024)
	for {
		_, err := conn.Read(buf)
		if err != nil {
			return
		}
		_, err = conn.Write(buf)
		if err != nil {
			return
		}
	}
}

func main() {
	listenfd, err := net.Listen("tcp", "0.0.0.0:8001")
	if err != nil {
		fmt.Println("listen ERROR:", err.Error())
		return
	}
	defer listenfd.Close()

	cur_conn_num := 0
	conn_chan := make(chan net.Conn)
	ch_conn_change := make(chan int)

	go func() {
		for conn_change := range ch_conn_change {
			cur_conn_num += conn_change
		}
	}()

	go func() {
		for _ = range time.Tick(1e8) {
			fmt.Printf("cur conn num:%d\n", cur_conn_num)
		}
	}()

    for i := 0; i < MAX_CONN_NUMS; i++ {
		go func() {
			for conn := range conn_chan {
				ch_conn_change <- 1
				EchoFunc(conn)
				ch_conn_change <- -1
			}
		}()
	}

	for {
		conn, err := listenfd.Accept()
		if err != nil {
			fmt.Println("accpet ERROR:", err.Error())
		}
		conn_chan <- conn
	}
}
