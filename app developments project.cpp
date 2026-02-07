import React, { useState } from 'react';
import { View, Text, TextInput, Button, FlatList } from 'react-native';

export default function App() {
  const [task, setTask] = useState();
  const [tasks, setTasks] = useState([]);

  const addTask = () => {
    if (task !== '') {
      setTasks([...tasks, { id: Date.now().toString(), name: task }]);
      setTask('');
    }
  };

  const deleteTask = (id) => {
    setTasks(tasks.filter(item => item.id !== id));
  };

  return (
    <View style={{ padding: 20 }}>
      <Text style={{ fontSize: 24 }}>Task Manager</Text>

      <TextInput
        placeholder="Enter task"
        value={task}
        onChangeText={setTask}
        style={{ borderWidth: 1, marginVertical: 10, padding: 8 }}
      />

      <Button title="Add Task" onPress={addTask} />

      <FlatList
        data={tasks}
        renderItem={({ item }) => (
          <View style={{ flexDirection: 'row', marginTop: 10 }}>
            <Text style={{ flex: 1 }}>{item.name}</Text>
            <Button title="Delete" onPress={() => deleteTask(item.id)} />
          </View>
        )}
        keyExtractor={item => item.id}
      />
    </View>
  );
}

