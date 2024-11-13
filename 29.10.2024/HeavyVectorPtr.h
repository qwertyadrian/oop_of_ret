#pragma once

struct HeavyVectorPtr { // Косвенно-адресное
    int size = 0;
    int length = 0;
    HeavyData **data;
};

HeavyVectorPtr initVectorPtr(size_t size) {
    HeavyVectorPtr *vector = new HeavyVectorPtr;
    vector->size = 0;
    vector->length = size;
    vector->data = new HeavyData*[size];

    return *vector;
}

bool vector_ptr_is_empty(const HeavyVectorPtr &vec) {
    return vec.size == 0;
}

HeavyData* vector_ptr_pop_back(HeavyVectorPtr &vec) {
    return vec.data[vec.size--];
}

void vector_ptr_resize(HeavyVectorPtr &vec, const int size) {
    HeavyData **new_data = new HeavyData*[size];
    for (int i = 0; i < vec.size - size; i++) {
        delete vector_ptr_pop_back(vec);
    }

    int min_size = (size < vec.size) ? size : vec.size;
    for (size_t i = 0; i < min_size; i++) {
        new_data[i] = vec.data[i];
    }
    delete[] vec.data;
    vec.data = new_data;
    if (size < vec.size) {
        vec.size = size;
    }
    vec.length = size;
}

HeavyData vector_ptr_at(const HeavyVectorPtr &vec, const int index) {
    if (index < 0 || index >= vec.size) {
        throw std::out_of_range("Index exceeds the length of the vector");
    }
    return *vec.data[index];
}

void vector_ptr_push_back(HeavyVectorPtr &vec, const HeavyData &data) {
    if (vec.size == vec.length) {
        vector_ptr_resize(vec, vec.length * 2);
    }
    vec.data[vec.size] = new HeavyData;
    *vec.data[vec.size] = data;
    vec.size++;
}

void vector_ptr_insert_at(HeavyVectorPtr &vec, const HeavyData &data, const int index) {
    if (index < 0 || index >= vec.size) {
        throw std::out_of_range("Index exceeds the length of the vector");
    }
    if (vec.size == vec.length) {
        vector_ptr_resize(vec, vec.length * 2);
    }
    for (size_t i = vec.size; i > index; i--) {
        vec.data[i] = vec.data[i - 1];
    }
    vec.data[index] = new HeavyData;
    *vec.data[index] = data;
    vec.size++;
}

void vector_ptr_push_front(HeavyVectorPtr &vec, const HeavyData &data) {
    vector_ptr_insert_at(vec, data, 0);
}

HeavyData* vector_ptr_remove_at(HeavyVectorPtr &vec, const int index) {
    if (index < 0 || index >= vec.size) {
        throw std::out_of_range("Index exceeds the length of the vector");
    }
    HeavyData *data = vec.data[index];
    for (size_t i = index; i < vec.size - 1; i++) {
        vec.data[i] = vec.data[i + 1];
    }
    vec.size--;
    return data;
}

void vector_ptr_swap(HeavyVectorPtr &vec, const int index1, const int index2) {
    if (index1 < 0 || index1 >= vec.size || index2 < 0 || index2 >= vec.size) {
        throw std::out_of_range("Index exceeds the length of the vector");
    }
    HeavyData *temp = vec.data[index1];
    vec.data[index1] = vec.data[index2];
    vec.data[index2] = temp;
}

void vector_ptr_move(HeavyVectorPtr &vec, const int from, const int to) {
    if (from < 0 || from >= vec.size || to < 0 || to >= vec.size) {
        throw std::out_of_range("Index exceeds the length of the vector");
    }
    if (from == to) return;
    HeavyData *data = vector_ptr_remove_at(vec, from);
    vector_ptr_insert_at(vec, *data, to);
}
