import pandas as pd

def createBonusColumn(employees: pd.DataFrame) -> pd.DataFrame:
    df=pd.DataFrame(employees)
    df['bonus']= df['salary']*2
    return df