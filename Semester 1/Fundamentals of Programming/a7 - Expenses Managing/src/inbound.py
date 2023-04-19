import sys
sys.path.insert(0, 'D:\\College\\Fundamentals_of_Programming\\Repos\\Assignments\\a7-913-Fintina-Olivia\\src\\repository\\inbound')

import repositoryJson
import repositoryText
import repositoryPickle
#import INsql

def pull_db():
    database = {}
    with open('src/settings.properties') as file:
        for line in file:
            if line[0]!='[':
                key, value = line.split('=')
                database[key] = value
     
    if database['database_name']=='json\n':
        #return INjson.loading()
        return repositoryJson.loading()
    
    elif database['database_name']=='txt\n':
        #return INtxt.loading()
        return repositoryText.loading()
    
    elif database['database_name']=='pickle\n':
        #return INpick.loading()
        return repositoryPickle.loading()
    
    elif database['database_name']=='sql\n':
        #return INsql.loading()
        pass
