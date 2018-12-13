### use virtualenv in jupyter notebook  
```
pip3 install -U jupyter
virtualenv tensorflow
source ~/tensorflow/bin/activate
pip3 install ipykernel

python3 -m ipykernel install --user --name=tensorflow
```
```
As it turns out, no. Computational graphs contain only the steps of computation; they do not contain the results. At least…not yet!
```
```
constant placeholder variable initializer
```
```
c = []
for d in ['/device:GPU:2', '/device:GPU:3']:
  with tf.device(d):
    a = tf.constant([1.0, 2.0, 3.0, 4.0, 5.0, 6.0], shape=[2, 3])
    b = tf.constant([1.0, 2.0, 3.0, 4.0, 5.0, 6.0], shape=[3, 2])
    c.append(tf.matmul(a, b))
with tf.device('/cpu:0'):
  sum = tf.add_n(c)
# Creates a session with log_device_placement set to True.
sess = tf.Session(config=tf.ConfigProto(log_device_placement=True))
# Runs the op.
print(sess.run(sum))
```
