//// Copyright 2014 BVLC and contributors.
//
//#include <algorithm>
//#include <cmath>
//#include <cfloat>
//#include <vector>
//
//#include "caffe/layer.hpp"
//#include "caffe/vision_layers.hpp"
//#include "caffe/util/math_functions.hpp"
//#include "caffe/util/io.hpp"
//
//using std::max;
//
//namespace caffe {
//
//template <typename Dtype>
//void QLossLayer<Dtype>::FurtherSetUp(
//  const vector<Blob<Dtype>*>& bottom, vector<Blob<Dtype>*>* top) {
//  CHECK_EQ(bottom[0]->channels(), bottom[1]->channels());
//  CHECK_EQ(bottom[0]->height(), bottom[1]->height());
//  CHECK_EQ(bottom[0]->width(), bottom[1]->width());
//  diff_.Reshape(bottom[0]->num(), bottom[0]->channels(),
//      bottom[0]->height(), bottom[0]->width());
//}
//
//template <typename Dtype>
//Dtype QLossLayer<Dtype>::Forward_cpu(const vector<Blob<Dtype>*>& bottom,
//    vector<Blob<Dtype>*>* top) {
//  // h(yi   Q (s, a; ✓i))2i
//  // return (Qold - Qnew) ^ 2
//
//  // We don't need loss yet, we just need the output activations and gradient.
//
////  int count = bottom[0]->count();
////  caffe_sub(
////      count,                       // n
////      bottom[0]->cpu_data(),       // a - activations
////      bottom[1]->cpu_data(),       // b - label
////      diff_.mutable_cpu_data());   // y - out
//
////  Dtype dot = caffe_cpu_dot(count, diff_.cpu_data(), diff_.cpu_data());
////  Dtype loss = dot / bottom[0]->num() / Dtype(2);
////  return loss;
//
//  return Dtype(0);
//}
//
//template <typename Dtype>
//void QLossLayer<Dtype>::Backward_cpu(const vector<Blob<Dtype>*>& top,
//    const bool propagate_down, vector<Blob<Dtype>*>* bottom) {
//
//  // [ (r + gamma * maxQ(s', a') - Q(s, a)) * Q(s, a)
//
//  // Pass reward (via label?)
//  // Hardcode gamma
//  //
//
//  caffe_cpu_axpby(
//      (*bottom)[0]->count(),              // count
//      Dtype(1) / (*bottom)[0]->num(),     // alpha
//      diff_.cpu_data(),                   // a
//      Dtype(0),                           // beta
//      (*bottom)[0]->mutable_cpu_diff());  // b
//}
//
//INSTANTIATE_CLASS(QLossLayer);
//
//}  // namespace caffe
