dep_c = 100

code_tmp = """\
#include<stdio.h>
int func{0}()
{{
    printf("%d\\n", {1});
}}
"""

for i in range(dep_c):
    idxs = str(i).zfill(2)
    open(f"dep"+idxs+".c", "w").write(
        code_tmp.format(idxs, str(i))
    )