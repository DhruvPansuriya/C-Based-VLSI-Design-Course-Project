; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_46 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg1_53 () (_ BitVec 32))
(assert
 (let ((?x75251 (bvmul arg0_6 arg1_46)))
(let ((?x61880 (bvmul (_ bv4294967295 32) ?x75251)))
(let ((?x63575 (bvmul arg0_6 arg1_53)))
(let ((?x73188 (bvadd ?x63575 ?x61880)))
(and (distinct ?x73188 (_ bv0 32)) true))))))
(check-sat)
