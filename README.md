# HyperparameterSteepness

[![DOI](https://zenodo.org/badge/323657993.svg)](https://zenodo.org/badge/latestdoi/323657993)


Very often in machine learning, one needs to control a hyperparameter value such as the learning rate over the epochs. A specific example would consist of an exponential decay of a learning rate eta over the epochs. However, the optimal shape of such a controlling curve is not known. Either a fast decay, linear decay or even a slow-start decay may be needed. Similar to the gamma parameter in image-intensity adjustment, a single parameter, here alpha, can control the convexity of the hyperparameter curve over epochs. We have used the trick in training of Kohohen maps and in controlling the leniency of a reward schedule in reinforcement learning (see below).

![Screenshot](steepness-curves.png)

Enclosed is the steepness .c program with a bash script and .png graph for several steepness (alpha) values. As an example, the hyperparameter value runs from 0.4 in the beginning to 0.01 at the end of a series of training epochs.

You can make the binary by gcc steepness.c -lm -o steepness 

To run the demo script you need to install gnuplot 
The *.curves file and .png are already made and present in the package.  

You can cite Schomaker &amp; Bulacu (2004), Eq. 8.  Schomaker, L &amp; Bulacu, M 2004, 'Automatic writer identification using connected-component contours and edge-based features of uppercase western script', IEEE transactions on pattern analysis and machine intelligence, vol. 26, no. 6, pp. 787-798.  

The function is also used in the following publication: 
```
@article{Luo_2020, 
  title={Accelerating Reinforcement Learning for Reaching Using Continuous Curriculum Learning}, 
  ISBN={9781728169262}, url={http://dx.doi.org/10.1109/IJCNN48605.2020.9207427}, 
  DOI={10.1109/ijcnn48605.2020.9207427}, 
  journal={2020 International Joint Conference on Neural Networks (IJCNN)}, 
  publisher={IEEE}, 
  author={Luo, Sha and Kasaei, Hamidreza and Schomaker, Lambert}, 
  year={2020}, month={Jul} 
}
```
