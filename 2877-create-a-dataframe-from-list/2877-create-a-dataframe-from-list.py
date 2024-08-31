import pandas as pd

def createDataframe(student_data: List[List[int]]) -> pd.DataFrame:
    col_name=['student_id','age']
    df=pd.DataFrame(student_data,columns=col_name)
    return df