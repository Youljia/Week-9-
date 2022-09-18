# Week-9-

## C++语言学习

### vector

* 如何引用vector？

  ```c++
  vector<int>& weights
  //此时的weights就是传入的vector的引用了
  ```

* 如何对vector的所有元素求和

  ```c++
  #include<numeric>
  int sum = accumulate(v.begin(), v.end(),0);
  //accumulate(开始地方，结束地方，额外加的数)
  ```

* 如何求vector里面元素的最大值和最小值

  ```c++
  #include<algorithm>
  int max = *max_element(v.begin(), v.end());
  int min = *min_element(v.begin(), v.end());
  ```

## 数据结构与算法

### 二分查找法

* 特点 --> 只能操作有序数列

  排序是二分查找法的前置条件！

* 时间复杂度

  每一次找到中间的元素，判断与目标元素的关系，再找跟判断，直至找到循环结束！

  --> 时间复杂度为O（logn）

* 二分查找法的变种

  * upper --> 寻找大于目标元素的最小值的最小索引
  * ceil --> 如果该元素存在，返回该元素的最大索引；如果该元素不存在，返回大于目标元素的最小值的最小索引
  * lower_ceil --> 如果该元素存在，返回该元素的最小索引；如果该元素不存在，返回大于目标元素的最小值的最小索引
  * lower --> 寻找小于目标元素的最大值的最大索引
  * lower_floor --> 如果元素存在，寻找目标元素的最小索引；如果元素不存在，返回小于目标元素的最大值的最大索引
  * upper_floor --> 如果元素存在，寻找目标元素的最大索引；如果元素不存在，返回小于目标元素的最大值的最大索引

* 死循环

  来源 --> int mid = l+(r-l)/2;  是向下取整，如果l=mid,则会造成死循环。

  1.l=mid    int mid = l+(r-l+1)/2

  2.l=mid+1   int mid = l+(r-l)/2

* 问题 --> leetcode1011题
 * 为何l从最大值开始而不是从一开始
 -->因为如果从1开始的话，永远运不走货物，必须从货物最重的开始才能运走全部货物！

