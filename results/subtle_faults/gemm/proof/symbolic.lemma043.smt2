; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_8 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg1_2 () (_ BitVec 32))
(assert
 (let ((?x175 (bvmul arg0_12 arg1_8)))
(let ((?x18337 (bvmul (_ bv4294967295 32) ?x175)))
(let ((?x95 (bvmul arg0_12 arg1_2)))
(let ((?x6857 (bvadd ?x95 ?x18337)))
(and (distinct ?x6857 (_ bv0 32)) true))))))
(check-sat)
