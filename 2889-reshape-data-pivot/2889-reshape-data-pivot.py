import pandas as pd

def pivotTable(weather: pd.DataFrame) -> pd.DataFrame:
    df = pd.DataFrame(weather)
    return df.pivot(index='month',columns='city', values='temperature')
