#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

#include <leveldb/db.h>
#include <iostream>
#include <string>

using namespace std;

int main(int argc,char *argv[])
{
    return Catch::Session().run(argc,argv);
}

TEST_CASE("Leveldb unit test","[leveldb]"){
    leveldb::DB *db;
    leveldb::Options options;
    options.create_if_missing = true;
    leveldb::Status status = leveldb::DB::Open(options,"/tmp/testdb",&db);

    REQUIRE(status.ok());

    SECTION("Put test"){
        string key = "徐德传";
        string value = "WNLO";

        status = db->Put(leveldb::WriteOptions(),key,value);
        REQUIRE(status.ok());

        string value_r;
        status = db->Get(leveldb::ReadOptions(),key,&value_r);
        REQUIRE(status.ok());
        REQUIRE(value == value_r);
    }

    SECTION("Delete test"){
        string key = "ACT";
        string value = "USNT";
        status = db->Put(leveldb::WriteOptions(),key,value);
        REQUIRE(status.ok());

        status = db->Delete(leveldb::WriteOptions(),key);
        REQUIRE(status.ok());

        string value_r;
        status = db->Get(leveldb::ReadOptions(),key,&value_r);
        REQUIRE(!status.ok());
        REQUIRE(value_r.empty());
    }

    delete db;
}
