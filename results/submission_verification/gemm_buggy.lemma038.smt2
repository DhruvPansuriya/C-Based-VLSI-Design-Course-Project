; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_2 () (_ BitVec 32))
(declare-fun arg0_14 () (_ BitVec 32))
(declare-fun arg1_8 () (_ BitVec 32))
(assert
 (let ((?x2592 (bvmul arg0_14 arg1_2)))
(let ((?x22332 (bvmul (_ bv4294967295 32) ?x2592)))
(let ((?x228 (bvmul arg0_14 arg1_8)))
(let ((?x9857 (bvadd ?x228 ?x22332)))
(and (distinct ?x9857 (_ bv0 32)) true))))))
(check-sat)
