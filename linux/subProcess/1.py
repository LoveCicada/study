import pandas as pd
import numpy as np
data1={
    'sex':['female','female','male','femal','male'],
    'city':['北京','上海','深圳','重庆','上海'],
    'age':[20,21,22,27,25],
    'name':['li','zhang','wang','liu','wu'],
    'year':[1994,1995,1997,2000,2002]
}
df7=pd.DataFrame(data1,
               columns=['name','sex','age','city','year'],
               index=[np.arange(5)])
# print('df7:\n',df7)

# | operator
df8 = df7[ (df7['age']==20) | (df7['sex']=='female')]
print('df8:\n', df8)

# & operator
df9 = df7[ (df7['age']==20) & (df7['sex']=='female')]
print('df9:\n', df9)

# where function
filter1 = (df7['age']==20)
filter2 = (df7['sex']=='female')
filter = filter1 | filter2
df10 = df7.where(filter)
print('df10:\n', df10)


