import pandas as pd

def concatenateTables(df1: pd.DataFrame, df2: pd.DataFrame) -> pd.DataFrame:
   a=pd.merge(df1,df2,on=['student_id','name','age'],how='outer')
   return a