import React from 'react';
import './TinderCard.css';

const TinderCard = ({ user, onSwipe }) => {
  return (
    <div className="tinder-card">
      <img src={user.img} alt={`${user.name}'s profile`} />
      <h3>{user.name}, {user.age}</h3>
      <p>{user.bio}</p>
      <div className="swipe-buttons">
        <button className="dislike-button" onClick={() => onSwipe(user, false)}>Dislike</button>
        <button className="like-button" onClick={() => onSwipe(user, true)}>Like</button>
      </div>
    </div>
  );
};

export default TinderCard;
