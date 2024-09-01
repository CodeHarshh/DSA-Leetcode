import pandas as pd

def findHeavyAnimals(animals: pd.DataFrame) -> pd.DataFrame:
    df=pd.DataFrame(animals)
    return df[df['weight'] >100].sort_values(by='weight',ascending=False)[['name']]