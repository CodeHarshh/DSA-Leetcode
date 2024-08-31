import pandas as pd

def renameColumns(students: pd.DataFrame) -> pd.DataFrame:
    df=pd.DataFrame(students)
    df=df.rename(columns={
        'id':'student_id','first':'first_name',
        'last':'last_name','age':'age_in_years' })
    return df