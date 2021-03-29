import simHelper
import tensorflow as tf
from tensorflow import keras
from tensorflow.keras import layers
import os.path
import numpy as np
from numpy import ndarray
from typing import Tuple

muscle_activation_file = "muscle_activations2.csv"
joint_accelerations_file = "joint_accelerations2.csv"


def data_exists():
    file_exists = lambda file: os.path.isfile(file)
    return file_exists(muscle_activation_file) and file_exists(joint_accelerations_file)


def save_data(state_array: Tuple[ndarray]):
    np.savetxt(muscle_activation_file, state_array[0], delimiter=',')
    np.savetxt(joint_accelerations_file, state_array[1], delimiter=',')


def load_data() -> Tuple:
    muscle_activations = np.loadtxt(muscle_activation_file, delimiter=',')
    joint_accelerations = np.loadtxt(joint_accelerations_file, delimiter=',')
    return muscle_activations, joint_accelerations


def my_metric_fn(y_true, y_pred):
    difference = y_true - y_pred
    return tf.reduce_mean(difference, axis=-1)


def train_model():
    if not data_exists():
        state_array: tuple = simHelper.simulate(1000000)
        save_data(state_array)
    else:
        state_array = load_data()

    muscle_activations, joint_accelerations = state_array
    joint_accelerations = joint_accelerations
    model = keras.Sequential(
        [
            layers.Dense(10, activation="sigmoid"),
            layers.Dense(10, activation="relu"),
            layers.Dense(4)
        ]
    )

    model.compile(
        optimizer=tf.optimizers.SGD(), loss="mean_absolute_error", metrics="mean_absolute_error"
    )

    model.fit(
        muscle_activations,
        joint_accelerations,
        epochs=1,
        batch_size=1
    )
    return model


model = train_model()
model.save("joint_acceleration_to_muscle_activation_network")
