import pandas as pd

def fillMissingValues(products: pd.DataFrame) -> pd.DataFrame:
    df = pd.DataFrame(products)
    df['quantity']=df['quantity'].fillna(0)
    return df