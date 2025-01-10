import React, { useState } from 'react';
import './App.css';
import TinderCard from './TinderCard';

function App() {
  // Sample users (in a real-world app, this would come from an API)
  const [users, setUsers] = useState([
    { id: 1, name: "Alice", age: 25, gender: "female", bio: "Love hiking!", img: "https://via.placeholder.com/150" },
    { id: 2, name: "Bob", age: 27, gender: "male", bio: "Dog lover and foodie.", img: "https://via.placeholder.com/150" },
    { id: 3, name: "Charlie", age: 24, gender: "male", bio: "Aspiring musician.", img: "https://via.placeholder.com/150" },
    { id: 4, name: "Diana", age: 26, gender: "female", bio: "Tech enthusiast.", img: "https://via.placeholder.com/150" }
  ]);

  const [matches, setMatches] = useState([]);
  
  // Handle swipe (right is like, left is dislike)
  const handleSwipe = (user, liked) => {
    if (liked) {
      setMatches(prev => [...prev, user]);
    }
    setUsers(prev => prev.filter(u => u.id !== user.id)); // Remove the swiped user
  };

  return (
    <div className="App">
      <h1>Tinder Clone</h1>
      <div className="tinder-cards-container">
        {users.length > 0 ? (
          users.map(user => (
            <TinderCard key={user.id} user={user} onSwipe={handleSwipe} />
          ))
        ) : (
          <h2>No more profiles</h2>
        )}
      </div>
      <div className="matches-section">
        <h2>Matches:</h2>
        {matches.length > 0 ? (
          matches.map(match => (
            <div key={match.id}>
              <p>{match.name}</p>
            </div>
          ))
        ) : (
          <p>No matches yet.</p>
        )}
      </div>
    </div>
  );
}

export default App;
