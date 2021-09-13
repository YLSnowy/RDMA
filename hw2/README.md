## run method
# server:
    make compile
    ./bw_template.o -d mlx5_0

# client
    make compile
    ./bw_template.o -d mlx5_0 server.ipaddress

## example
# server
    make clean
    make compile
    ./bw_template.o -d mlx5_0

# client
    make clean
    make compile
    ./bw_template.o -d mlx5_0 192.168.3.3

## result
bytes          throughput       uint
8192            77.101176       Gbps
16384           81.920000       Gbps
32768           48.998879       Gbps
65536           53.227208       Gbps
131072          68.311140       Gbps
262144          67.432540       Gbps
524288          80.504875       Gbps
1048576         87.290406       Gbps
2097152         88.138776       Gbps
4194304         88.394183       Gbps
8388608         88.493260       Gbps
16777216        88.557487       Gbps
33554432        88.560409       Gbps
67108864        88.554566       Gbps
134217728       88.427670       Gbps
268435456       88.005854       Gbps
536870912       86.446379       Gbps
