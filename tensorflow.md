### use virtualenv in jupyter notebook  
```
pip3 install -U jupyter
virtualenv tensorflow
source ~/tensorflow/bin/activate
pip3 install ipykernel

python3 -m ipykernel install --user --name=tensorflow
```
