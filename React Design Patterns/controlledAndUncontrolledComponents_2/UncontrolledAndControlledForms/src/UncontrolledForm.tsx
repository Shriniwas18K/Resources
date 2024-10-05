// In UncontrolledForm i.e. Uncontrolled Component keeps its state
// only inside it , all changes in it are only detectable by triggering 
// any event in it
import React, { FC, useRef } from 'react';
import { Form,Input,SubmitButton,FormData } from './FormStyles';
export const UncontrolledForm: FC = () => {
  // Use refs to hold DOM element references
  const nameInput = useRef<HTMLInputElement>(null);
  const ageInput = useRef<HTMLInputElement>(null);
  const hairColorInput = useRef<HTMLInputElement>(null);

  // Handle form submission
  const handleSubmit = (event: React.FormEvent<HTMLFormElement>) => {
    event.preventDefault();

    // Access form data using refs
    const formData: FormData = {
      name: nameInput.current!.value,
      age: parseInt(ageInput.current!.value, 10), // Parse age as a number
      hairColor: hairColorInput.current!.value,
    };

    // Process the form data (e.g., send to server, display)
    console.log('Form data:', formData);

    // Optionally clear form after submission
    nameInput.current!.value = '';
    ageInput.current!.value = '';
    hairColorInput.current!.value = '';
  };

  return (
    <>
      <Form onSubmit={handleSubmit}>
        <Input name='name' type='text' placeholder='Name' ref={nameInput} />
        <Input name='age' type='number' placeholder='Age' ref={ageInput} />
        <Input name='hairColor' type='text' placeholder='Hair Color' ref={hairColorInput} />
        <SubmitButton type='submit' value="submit" />
      </Form>
    </>
  );
};
