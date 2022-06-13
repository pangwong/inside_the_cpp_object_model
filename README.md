## Performance Test Code for Book Inside-the-cpp-object-model



## Platform

> macOS 12.4
>
> 3.1 GHz Dual-Core Intel Core i5
> 
> Apple clang version 13.1.6 (clang-1316.0.21.2.5)
>
> Complie Options:  -O3 -std=c++11



## Data Semantics

#### Data Store & Get without Inheritance

```shell
run 10000000 * loop times where loop=100000000
01.local_array                     	 run time: 	237844	micro second
02.c_struct                        	 run time: 	233202	micro second
03.class_inline_get_reference      	 run time: 	237401	micro second
04.class_inline_get_set            	 run time: 	233790	micro second
```

#### Data Store & Get with Inheritance

```shell
run 10000000 * loop times where loop=100000
05.class_single_inheritance        	 run time: 	386.151	micro second
06.class_single_virtual_inheritance	 run time: 	1.17685e+07	micro second
07.class_double_virtual_inheritance	 run time: 	1.23378e+07	micro second
```

#### Data Store & Get without Inheritance using Data Member Pointer

```shell
run 10000000 * loop times where loop=100000000
02.c_struct                        	 run time: 	233638	micro second
08.class_pointer_to_obj_member     	 run time: 	231789	micro second
09.class_pointer_to_class_member   	 run time: 	232280	micro second
```

#### Data Store & Get with Inheritance using Data Member Pointer

```shell
run 10000000 * loop times where loop=100000
09.class_pointer_to_class_member   	 run time: 	309.065	micro second
10.pointer_single_inheritance      	 run time: 	324.721	micro second
11.pointer_single_virtual_inheritance	 run time: 	1.2629e+07	micro second
12.pointer_double_virtual_inheritance	 run time: 	1.18064e+07	micro second
```

#### All Cases

```shell
run 10000000 * loop times where loop=1
01.local_array                     	 run time: 	0.244	micro second
02.c_struct                        	 run time: 	0.115	micro second
03.class_inline_get_reference      	 run time: 	0.115	micro second
04.class_inline_get_set            	 run time: 	0.107	micro second
05.class_single_inheritance        	 run time: 	0.123	micro second
06.class_single_virtual_inheritance	 run time: 	353.464	micro second
07.class_double_virtual_inheritance	 run time: 	351.704	micro second
08.class_pointer_to_obj_member     	 run time: 	0.149	micro second
09.class_pointer_to_class_member   	 run time: 	0.108	micro second
10.pointer_single_inheritance      	 run time: 	0.123	micro second
11.pointer_single_virtual_inheritance	 run time: 	322.768	micro second
12.pointer_double_virtual_inheritance	 run time: 	288.367	micro second
```



## Function Semantics

#### Non-Virtual Functions

```cpp
run 10000000 * loop times where loop=100000000
01.ni_nonmember_function                    	 run time: 	212417	micro second
02.ni_nonstatic_member_function             	 run time: 	204715	micro second
03.ni_static_member_function                	 run time: 	206989	micro second
04.ni_virtual_member_function               	 run time: 	204593	micro second
```

#### Virtual Functions

```shell
run 10000000 * loop times where loop=10
05.si_virtual_member_function_primary_base  	 run time: 	168602	micro second
06.si_virtual_member_function_secondary_base	 run time: 	157024	micro second
07.mi_virtual_member_function_primary_base  	 run time: 	152839	micro second
08.mi_virtual_member_function_secondary_base	 run time: 	197000	micro second
09.vi_virtual_member_function               	 run time: 	157466	micro second
```

#### Non-Virtual Functions Pointers

```shell
run 10000000 * loop times where loop=10
10.ni_nonmember_function_pointer                    	 run time: 	218986	micro second
11.ni_nonstatic_member_function_pointer             	 run time: 	219323	micro second
12.ni_static_member_function_pointer                	 run time: 	227311	micro second
13.ni_virtual_member_function_pointer               	 run time: 	226420	micro second
```

#### Virtual Functions Pointers

```cpp
run 10000000 * loop times where loop=10
14.si_virtual_member_function_pointer_primary_base  	 run time: 	155641	micro second
15.si_virtual_member_function_pointer_secondary_base	 run time: 	146306	micro second
16.mi_virtual_member_function_pointer_primary_base  	 run time: 	149420	micro second
17.mi_virtual_member_function_pointer_secondary_base	 run time: 	147199	micro second
18.vi_virtual_member_function_pointer               	 run time: 	179268	micro second
```

#### All Cases

```shell
run 10000000 * loop times where loop=10
01.ni_nonmember_function                            	 run time: 	0.229	micro second
02.ni_nonstatic_member_function                     	 run time: 	0.1	micro second
03.ni_static_member_function                        	 run time: 	0.121	micro second
04.ni_virtual_member_function                       	 run time: 	0.117	micro second
05.si_virtual_member_function_primary_base          	 run time: 	159903	micro second
06.si_virtual_member_function_secondary_base        	 run time: 	146265	micro second
07.mi_virtual_member_function_primary_base          	 run time: 	149077	micro second
08.mi_virtual_member_function_secondary_base        	 run time: 	177187	micro second
09.vi_virtual_member_function                       	 run time: 	150175	micro second
10.ni_nonmember_function_pointer                    	 run time: 	0.254	micro second
11.ni_nonstatic_member_function_pointer             	 run time: 	0.137	micro second
12.ni_static_member_function_pointer                	 run time: 	0.108	micro second
13.ni_virtual_member_function_pointer               	 run time: 	0.102	micro second
14.si_virtual_member_function_pointer_primary_base  	 run time: 	147038	micro second
15.si_virtual_member_function_pointer_secondary_base	 run time: 	145957	micro second
16.mi_virtual_member_function_pointer_primary_base  	 run time: 	145731	micro second
17.mi_virtual_member_function_pointer_secondary_base	 run time: 	145503	micro second
18.vi_virtual_member_function_pointer               	 run time: 	175097	micro second
```


## Different Compile Option

Performance difference when using different compile options  for `Data Store & Get without Inheritance`

#### using -O0

```shell
run 10000000 * loop times where loop=10
01.local_array                     	 run time: 	223281	micro second
02.c_struct                        	 run time: 	217732	micro second
03.class_inline_get_reference      	 run time: 	3.21037e+06	micro second
04.class_inline_get_set            	 run time: 	3.41993e+06	micro second
```

#### using -O1

```shell
run 10000000 * loop times where loop=10
01.local_array                     	 run time: 	0.965	micro second
02.c_struct                        	 run time: 	0.681	micro second
03.class_inline_get_reference      	 run time: 	1.37085e+06	micro second
04.class_inline_get_set            	 run time: 	1.28977e+06	micro second
```

#### using -O2

```shell
run 10000000 * loop times where loop=10
01.local_array                     	 run time: 	0.407	micro second
02.c_struct                        	 run time: 	0.276	micro second
03.class_inline_get_reference      	 run time: 	0.243	micro second
04.class_inline_get_set            	 run time: 	0.25	micro second
```

#### using -O3

```shell
run 10000000 * loop times where loop=10
01.local_array                     	 run time: 	0.472	micro second
02.c_struct                        	 run time: 	0.248	micro second
03.class_inline_get_reference      	 run time: 	0.25	micro second
04.class_inline_get_set            	 run time: 	0.233	micro second
```
