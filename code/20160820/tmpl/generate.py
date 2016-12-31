#!/usr/bin/env python
# encoding: utf-8

import em

try:
    from cStringIO import StringIO
except ImportError:
    from StringIO import StringIO

import argparse


class RPCGenerator():
    def __init__(self, srvname, author, output_dir):
        self.srvname = srvname
        self.author = author
        self.output_dir = output_dir
        self.__inter = em.Interpreter()
        self.__output = StringIO()

    def __inter_process(self,tmpl,output_file):
        self.__ouput.reset()
        self.__inter.update(open(tmpl,'r'))


        with fp = open(output_file):
            fp.write(self.__output.getvalue())

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('-a','--author',type=str,help='code author, eg: linghutf')
    parser.add_argument('-o','--ouput',type=str,help='output dir, default: None')

    sub = parser.add_subparsers(help='service framework',dest='sub')
    srv = sub.add_parser('srv')
    rpc = sub.add_parser('rpc')

    srv.add_argument('-n','--server',type=str,help='server name')

    rpc.add_argument('-n','--server',type=str,help='server name')
    rpc.add_argument('-r','--rpc',type=str,help='rpc task name')
    rpc.add_argument('-req','--request',type=str,help='request name')
    rpc.add_argument('-res','--response',type=str,help='response name')

    args = parser.parse_args()
    print args
    print args.author
    print args.request

