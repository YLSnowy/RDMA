## run method
# server:
    make all
    ./ucp_client_server
# client
    make client
    ./ucp_client_server server.ipaddress


## result
bytes     throughput    uint
16          1.048049    Gbps
32          2.112021    Gbps
64          2.312945    Gbps
128         4.084947    Gbps
256         7.624882    Gbps
512        10.870341    Gbps
1024       13.334798    Gbps
2048       20.976245    Gbps
4096       10.210585    Gbps
8192       16.389791    Gbps
16384      24.426644    Gbps
32768      35.543174    Gbps
65536      41.489136    Gbps
131072     55.676229    Gbps
262144     67.535568    Gbps
524288     75.664023    Gbps
1048576    80.781785    Gbps
2097152    83.334551    Gbps
4194304    85.647460    Gbps
8388608    86.410918    Gbps
16777216   86.939891    Gbps